<br/>
<br/>
<div class="center-nav">
	<ul class="nav nav-tabs">
	    <li><a class="active btn btn-success" href="index.php">Portfolio</a></li>
		<li><a class="btn btn-success" href="quote.php">Get Quote</a></li>
		<li><a class="btn btn-success" href="buy.php">Buy Stock</a></li>
		<li><a class="btn btn-success" href="sell.php">Sell Stock</a></li>
		<li><a class="btn btn-success" href="history.php">History</a></li>
		<li><a class="btn btn-success" href="deposit.php">Deposit Funds</a></li>
		<li><a class="btn btn-success" href="logout.php"><strong>Log Out</strong></a></li>
	</ul>
</div>
<br/>
<div>
	<h4>Your current cash balance is:</h4><h4 class="text-success">$<?=number_format($cash[0]["cash"], 2)?></h4>
</div>
<br/>
<table id="table-portfolio" class="table table-striped">
	<thead>
	<tr class="success">
		<td class="text-success"><strong>Stock Symbol</strong></td>
		<td class="text-success"><strong>Stock Name</strong></td>
		<td class="text-success"><strong>Number of Shares</strong></td>
		<td class="text-success"><strong>Current Stock Price</strong></td>
		<td class="text-success"><strong>Total Invested in Stock</strong></td>
	</tr>
	</thead>
	<tbody class="table table-striped">
	<tr>
	<?php
		foreach ($portfolio as $row)
		{
			print("<tr>");
			print("<td class='text-success'>" . $row["symbol"] . "</td>");
	    	print("<td class='text-success'>" . $row["name"] . "</td>");
	    	print("<td class='text-success'>" . $row["shares"] . "</td>");
	    	print("<td class='text-success'>" . "$" . number_format($row["price"], 2) . "</td>");
	    	print("<td class='text-success'>" . "$" . number_format($row["total"], 2) . "</td>");
	    	print("</tr>");
    	}
    ?>
</tr>
	</tbody>
</table>



