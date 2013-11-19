$(document).ready(function() {

	// create autocomplete
	$('#form-quote input[name=symbol]').on('keyup', function() {
		
		// load autocomplete data from suggest.php
		$.ajax({
			url: 'suggest_more.php',
			type: 'POST',
			dataType: 'json',
			data: {
				symbol: $(this).val()
			},
			success: function(response) {
				// build html for a list of suggestions
				var suggestions = '<ul class="unstyled">';
				for (var i in response.symbols)
				{
					suggestions += '<li><a href="#" class="suggestion" data-symbol="' + response.symbols[i].symbol + '">' + response.symbols[i].name + '</a></li>';
				}

				// display list of suggestions
				suggestions += '<ul>';
				$('#suggestions').html(suggestions);
			}
		});
	});

	// set value of symbol field when a suggestion is clicked
	$('#suggestions').on('click', '.suggestion', function(){
		$('#form-quote input[name=symbol]').val($(this).attr('data-symbol'));
	});

	// load data via ajax when form is submitted
	$('#form-quote').on('submit', function() {

		// determine symbol
		var symbol = $('#form-quote input[name=symbol]').val();

		// send request to quote.php
		$.ajax({
			url: 'quote.php',
			type: 'POST',
			data: {
				  symbol: symbol
			},
			success: function(response) {
				$('#price').text(response);
			}
		});

		// since we're overridding form submission, make sure it doesn't submit
		return false;
	});
});