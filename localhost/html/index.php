<?php

    // configuration
    require("../includes/config.php");

    // query user's protfolio database
    $rows = query("SELECT symbol, shares FROM portfolio WHERE id = ?", $_SESSION["id"]);

    // define portfolio array for table data
    $portfolio = [];
    
    // for each of the user's stocks
    foreach ($rows as $row)
    {
    	// using the stock's symbol, lookup data in row
    	$stock = lookup($row["symbol"]);
    	
    	// if user has stock's in portfolio
    	if ($stock !== false)
    	{
    		$portfolio[] = [
    			"name" => $stock["name"],
    			"price" => $stock["price"],
    			"shares" => number_format($row["shares"], 0),
    			"symbol" => strtoupper($row["symbol"]),
    			"total" => ($row["shares"] * $stock["price"])
    		];
    	}
    }

    // query for user's cash balance
    $cash = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);

    // render portfolio
    render("portfolio.php", ["cash" => $cash, "portfolio" => $portfolio, "title" => "Portfolio"]);

?>
