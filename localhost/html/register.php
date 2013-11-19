<?php
	
	// configuration
	require("../includes/config.php");

	// if form was submitted
	if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
		// validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide a username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide a password.");
        }

		// passwords must match
		else if ($_POST["confirmation"] != $_POST["password"])
		{
			apologize("Your passwords do not match; please retry.");
		}

		// insert new user into database
		$new_user = query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", 
			$_POST["username"], crypt($_POST["password"]));

		// check for valid username
		if ($new_user === false)
		{
			apologize("Username already exists; please enter a different username.");
		}


		else
		{
			// find user id
			$rows = query("SELECT LAST_INSERT_ID() AS id");
			$id = $rows[0]["id"];

			// remember that user's now logged in by storing user's ID in session
	        $_SESSION["id"] = $id;

	        // redirect to portfolio
	        redirect("http://localhost/index.php");
		}
	}

	else
	{
		// else render form
		render("register_form.php", ["title" => "Register"]);
	}

?>