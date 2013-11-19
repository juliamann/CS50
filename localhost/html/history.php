<?php

    // configuration
    require("../includes/config.php");

    // query history data in database for history_form table
    $table = query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);

	// render history_form
	render("history_form.php", ["title" => "History", "table" => $table]);
?>