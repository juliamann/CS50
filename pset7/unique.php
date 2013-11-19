<?php

    // open file
    $file = file("file.txt");

    // remove dulpicate values from file
    $file = array_unique($file);

    // sort the array alphabetically
    sort($file);

    // print to stdout
    foreach ($file as $line)
    {
        echo $line;
    }
    
?>