#!/usr/bin/php

<?php
	
	$var = 7;
	printf("var is a %s\n", gettype($var));

	$var = "cs50 rocks!";
	printf("var is a %s\n", gettype($var));

	$var = true;
	printf("var is a %s\n", gettype($var));

	$var = fopen("dynamic.php", "r");
	printf("var is a %s\n", gettype($var));

	print("1" + 2);
	print("\n");
	print("CS" + 50);
	print("\n");
	print(1 + "2");
	print("\n");
	print(90 + "9 bottles of beer on the wall");
	print("\n");
	print(10 / 7);
	print("\n");
	print(7 + true);
	print("\n");

?>