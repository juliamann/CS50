<select name="concentration">

	<?php

		$file = file("concentrations.txt");

		foreach ($file as $concentraction)
		{
			echo '<option value="' . $concentraction . '">' . $concentraction . '</option>';
		}

	?>

</select>