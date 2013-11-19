<br/>
<br/>
<div class="center-nav">
    <ul class="nav nav-tabs">
        <li><a class="btn btn-success" href="index.php">Portfolio</a></li>
        <li><a class="btn btn-success" href="quote.php">Get Quote</a></li>
        <li><a class="active btn btn-success" href="buy.php">Buy Stock</a></li>
        <li><a class="btn btn-success" href="sell.php">Sell Stock</a></li>
        <li><a class="btn btn-success" href="history.php">History</a></li>
        <li><a class="btn btn-success" href="deposit.php">Deposit Funds</a></li>
        <li><a class="btn btn-success" href="logout.php"><strong>Log Out</strong></a></li>
    </ul>
</div>
<br/>
<form action="buy.php" method="post">
    <fieldset>
        <div class="control-group">
            <input name="symbol" placeholder="Stock Symbol" type="text"/>
        </div>
        <div class="control-group">
            <input name="shares" placeholder="Number of Shares" type="text"/>
        </div>
        <div class="control-group">
            <button type="submit" class="btn btn-success">Buy Stock!</button>
        </div>
    </fieldset>
</form>
<br/>