<br/>
<br/>
<div class="center-nav">
	<ul class="nav nav-tabs">
	    <li><a class="btn btn-success" href="index.php">Portfolio</a></li>
		<li><a class="btn btn-success" href="quote.php">Get Quote</a></li>
		<li><a class="btn btn-success" href="buy.php">Buy Stock</a></li>
		<li><a class="btn btn-success" href="sell.php">Sell Stock</a></li>
		<li><a class="active btn btn-success" href="history.php">History</a></li>
		<li><a class="btn btn-success" href="deposit.php">Deposit Funds</a></li>
		<li><a class="btn btn-success" href="logout.php"><strong>Log Out</strong></a></li>
	</ul>
</div>
<br/>
<table class="table table-striped">
	<thead>
	<tr class="success">
		<td class="text-success"><strong>Transaction Type</strong></td>
		<td class="text-success"><strong>Date/Time</strong></td>
		<td class="text-success"><strong>Symbol</strong></td>
		<td class="text-success"><strong>Name</strong></td>
		<td class="text-success"><strong>Shares</strong></td>
		<td class="text-success"><strong>Price</strong></td>
		<td class="text-success"><strong>Total</strong></td>
	</tr>
	</thead>
	<tbody class="table table-striped">
	<?php
		foreach ($table as $row)
		{
			print("<tr>");
			print("<td class='text-success'>" . $row["transaction"] . "</td>");
	    	print("<td class='text-success'>" . $row["timedate"] . "</td>");
	    	print("<td class='text-success'>" . $row["symbol"] . "</td>");
	    	print("<td class='text-success'>" . $row["name"] . "</td>");
	    	print("<td class='text-success'>" . $row["shares"] . "</td>");
	    	print("<td class='text-success'>" . "$" . number_format($row["price"], 2) . "</td>");
	    	print("<td class='text-success'>" . "$" . number_format($row["total"], 2) . "</td>");
	    	print("</tr>");
    	}
    ?>
	</tbody>
</table>
<br/>