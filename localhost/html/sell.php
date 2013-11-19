<?php

    // configuration
    require("../includes/config.php"); 

    // if form was submitted
	if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
		// set transaction type
        $type = 'SELL';

        // lookup stock infomation
    	$stock = lookup($_POST["symbol"]);

    	// get number of user's shares of that stock 
    	$shares = query("SELECT shares FROM portfolio WHERE id = ? AND symbol = ?",
    										 $_SESSION["id"], $_POST["symbol"]);

    	// calculate value of stocks they are selling
    	$total = $stock["price"] * $shares[0]["shares"];

		// update history
        query("INSERT INTO history (id, transaction, symbol, name, shares, price, total) 
            VALUES(?, ?, ?, ?, ?, ?, ?)", $_SESSION["id"], $type, $_POST["symbol"], 
            $stock["name"], $shares[0]["shares"], $stock["price"], $total);

        // deposit stock earnings to user account
		query("UPDATE users SET cash = cash + ? WHERE id = ?", $total, $_SESSION["id"]);
		
        // delete stock from database
		query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", 
							$_SESSION["id"], $_POST["symbol"]);

		// redirect to portfolio
        redirect("/");

        }

	// if form has not been submitted yet
	else
	{
        // get user's portfolio for stock info
        $rows = query("SELECT * FROM portfolio WHERE id = ?", $_SESSION["id"]);

		// create an array to store user's stock symbols
		$symbols = [];

    	// for each of the stocks
    	foreach ($rows as $row)
    	{
    		// save stock symbol
    		$symbol = $row["symbol"];

    		// add stock symbol to the array
    		$symbols[] = $symbol;
    	}

		// render sell_form template
    	render("sell_form.php", ["symbols" => $symbols, "title" => "Sell Stock"]);
	}

?>