<br/>
<br/>
<div class="center-nav">
	<ul class="nav nav-tabs">
	    <li><a class="btn btn-success" href="index.php">Portfolio</a></li>
		<li><a class="active btn btn-success" href="quote.php">Get Quote</a></li>
		<li><a class="btn btn-success" href="buy.php">Buy Stock</a></li>
		<li><a class="btn btn-success" href="sell.php">Sell Stock</a></li>
		<li><a class="btn btn-success" href="history.php">History</a></li>
		<li><a class="btn btn-success" href="deposit.php">Deposit Funds</a></li>
		<li><a class="btn btn-success" href="logout.php"><strong>Log Out</strong></a></li>
	</ul>
</div>
<br/>
<form id="form-quote" action="quote.php" method="post">
    <fieldset>
        <div class="control-group">
            <input autofocus autocomplete="off" name="symbol" placeholder="Enter stock symbol" type="text"/>
        </div>
        <div class="control-group">
            <button type="submit" class="btn btn-success">Get Quote!</button>
        </div>
    </fieldset>
    <br/>
    <div id="price"></div>
    <br/>
    <div id="suggestions"></div>
</form>
<script type="text/javascript" src="/js/symbols.js"></script>
<script type="text/javascript" src="/js/quote3.js"></script>