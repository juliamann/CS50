<?php

	// configuration
    require("../includes/config.php");

    // if form was submitted
	if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
		// ensure user enters whole, positive number of shares
		// returns true iff $_POST["shares"] contains a non-negative integer
		if (preg_match("/^\d+$/", $_POST["shares"]) == false)
		{
			apologize("Invalid number of shares. Try again.");
		}


		// make sure user enters a symbol
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a valid stock symbol.");
        }

        // make sure symbol user entered is valid
        if (lookup($_POST["symbol"]) === false)
        {
        	apologize("You must provide a valid stock symbol.");
        }

		// set transaction type
		$type = 'BUY';

		// lookup stock info
		$stock = lookup($_POST["symbol"]);

		// save stock symbol in uppercase
		$_POST["symbol"] = strtoupper($_POST["symbol"]);

		// get users cash amount
		$cash = query("SELECT cash FROM users where id = ?", $_SESSION["id"]);

		// get total cost of stocks user wants to buy
		$total = $stock["price"] * $_POST["shares"];

		// check to make sure user has enough cash to buy stock
		if ($cash[0]["cash"] < $total)
		{
			apologize("Can't afford that!");
		}

		else
		{
			// subtract cash from database
			query("UPDATE users SET cash = cash - ? WHERE id = ?", $total,
						$_SESSION["id"]);

			// add new shares to portfolio
			query("INSERT INTO portfolio (id, symbol, shares) VALUES(?, ?, ?) 
				ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", 
				 $_SESSION["id"], $_POST["symbol"], $_POST["shares"]);

			// update history
			query("INSERT INTO history (id, transaction, symbol, name, shares, price, total) 
				VALUES(?, ?, ?, ?, ?, ?, ?)", $_SESSION["id"], $type, $_POST["symbol"], 
				$stock["name"], $_POST["shares"], $stock["price"], $total);
		
			// redirect to portfolio
        	redirect("/");
		}
	}

	else
	{
		// else render buy_form
	    render("buy_form.php", ["title" => "Buy Stock"]);
	}
?>