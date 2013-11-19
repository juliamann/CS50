<br/>
<br/>
<div class="center-nav">
	<ul class="nav nav-tabs">
	    <li><a class="btn btn-success" href="index.php">Portfolio</a></li>
		<li><a class="btn btn-success" href="quote.php">Get Quote</a></li>
		<li><a class="btn btn-success" href="buy.php">Buy Stock</a></li>
		<li><a class="active btn btn-success" href="sell.php">Sell Stock</a></li>
		<li><a class="btn btn-success" href="history.php">History</a></li>
		<li><a class="btn btn-success" href="deposit.php">Deposit Funds</a></li>
		<li><a class="btn btn-success" href="logout.php"><strong>Log Out</strong></a></li>
	</ul>
</div>
<br/>
<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select class="form-control" name="symbol">
            	<option> </option>
            		<?php
	            		foreach ($symbols as $symbol)
	            		{
	            			print("<option>" . $symbol . "</option>");
	            		}
            		?>
            </select>
        </div>
        <div class="form group">
            <button type="submit" class="btn btn-success">Sell Stock!</button>
        </div>
    </fieldset>
</form>
<br/>