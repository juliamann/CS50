<?php

    // configuration
    require("../includes/config.php");
    
    // if form was submitted
	if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
		// make sure user enters a cash amount
        if (empty($_POST["cash"]))
        {
            apologize("Invalid deposit amount. Try again.");
        }

        // make sure user enters a number for cash amount
        if (!is_numeric($_POST["cash"]) || $_POST["cash"] < .01)
        {
        	apologize("Invalid deposit amount. Try again.");
        }

		// add new shares to portfolio
			query("INSERT INTO users (id, cash) VALUES(?, ?) 
				ON DUPLICATE KEY UPDATE cash = cash + VALUES(cash)", 
				 $_SESSION["id"], $_POST["cash"]);

	    // redirect to portfolio
        redirect("/");
	}

	else
	{
	    // render deposit_form
	    render("deposit_form.php", ["title" => "Deposit"]);
	}


?>