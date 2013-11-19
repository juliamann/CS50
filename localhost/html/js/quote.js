$(document).ready(function() {

	// load data via ajax when form is submitted
	$('#form-quote input[type=text]').on('keyup', function() {

		// determine symbol
		var symbol_value = $('#form-quote input[name=symbol]').val();

		// send request to quote.php
		$.ajax({
			url: 'quote.php',
			type: 'POST',
			data: {
				symbol: symbol_value
			},
			success: function(response) {
				$('#price').text(response);
			}
		}); 

		// since we're overridding form submission, make sure it doesn't submit
		//return false;
	});
});