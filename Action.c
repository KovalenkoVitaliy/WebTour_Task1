Action()
{
	int j;

	for (j=0; j<3; j++){ 
	
	
	web_reg_save_param_ex(
		"ParamName=SeatingPref",
		"LB=seatPref\" value=\"",
		"RB=\"",
		"Ordinal={Random3}",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=TypeofSeat",
		"LB=seatType\" value=\"",
		"RB=\"",
		"Ordinal={Random4}",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=RoundTrip",
		"LB=roundtrip\" value=\"",
		"RB=\"",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	
	
	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=CostticketOut",
		"LB=\"outboundFlight\" value=\"",
		"RB=\"",
		"Ordinal={Random1}",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=CostticketReturn",
		"LB=\"returnFlight\" value=\"",
		"RB=\"",
		"Ordinal={Random2}",
		SEARCH_FILTERS,
		LAST);
	
	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value={Discount}", ENDITEM, 
		"Name=depart", "Value={HomeCity}", ENDITEM, 
		"Name=departDate", "Value={DepartDate}", ENDITEM, 
		"Name=arrive", "Value={ArriveCity}", ENDITEM, 
		"Name=returnDate", "Value={ReturnDate}", ENDITEM, 
		"Name=numPassengers", "Value={NumberPassengers}", ENDITEM, 
		"Name=roundtrip", "Value={RoundTrip}", ENDITEM, 
		"Name=seatPref", "Value={SeatingPref}", ENDITEM, 
		"Name=seatType", "Value={TypeofSeat}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=65", ENDITEM, 
		"Name=findFlights.y", "Value=9", ENDITEM, 
		LAST);
	
		lr_output_message("Departure City: %s",lr_eval_string("{HomeCity}"));
		lr_output_message("Cost ticket OUT: %s",lr_eval_string("{CostticketOut}"));
		lr_output_message("Cost ticket Return: %s",lr_eval_string("{CostticketReturn}"));
		lr_output_message("Seating Preference: %s",lr_eval_string("{SeatingPref}"));
		lr_output_message("Type of Seat: %s",lr_eval_string("{TypeofSeat}"));
		lr_output_message("");

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={CostticketOut}", ENDITEM, 
		"Name=returnFlight", "Value={CostticketReturn}", ENDITEM, 
		"Name=numPassengers", "Value={NumberPassengers}", ENDITEM, 
		"Name=advanceDiscount", "Value={Discount}", ENDITEM, 
		"Name=seatType", "Value={TypeofSeat}", ENDITEM, 
		"Name=seatPref", "Value={SeatingPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=64", ENDITEM, 
		"Name=reserveFlights.y", "Value=3", ENDITEM, 
		LAST);


	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={StreetAddress}", ENDITEM, 
		"Name=address2", "Value={CityStateZip}", ENDITEM, 
		"Name=pass1", "Value={FullName}", ENDITEM, 
		"Name=creditCard", "Value={CreditCard}", ENDITEM, 
		"Name=expDate", "Value={ExpDateCard}", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value={NumberPassengers}", ENDITEM, 
		"Name=seatType", "Value={TypeofSeat}", ENDITEM, 
		"Name=seatPref", "Value={SeatingPref}", ENDITEM, 
		"Name=outboundFlight", "Value={CostticketOut}", ENDITEM, 
		"Name=advanceDiscount", "Value={Discount}", ENDITEM, 
		"Name=returnFlight", "Value={CostticketReturn}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=74", ENDITEM, 
		"Name=buyFlights.y", "Value=19", ENDITEM, 
		LAST);


	}
	
	return 0;
}