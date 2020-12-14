

function method02(){
    StartDate = 2019;
    LookBack = 66;          // 3 months
    vars Price = series(priceLow());
    var min_week = MinVal(Price, 5);
	var max_week = MaxVal(Price, 5);
	var min_month3s = MinVal(Price, 66);
	var max_month3s = MaxVal(Price, 66);
	var last = Price[0];
	var prevLast = Price[1];
	if(max_month3s < min_month3s * 1.21
		&& max_week > min_week && max_week < min_week * 1.11
		&& last > min_month3s
		&& last > prevLast
		&& max_month3s > min_week * 1.04){
		Stop = Trail = 0.08 * price();
		TakeProfit = 0.15 * price();
        enterLong();
    }
}

function method01(){
    LookBack = 66;          // 3 months
    vars Price = series(priceClose());
    var min_week = MinVal(Price, 5);
	var max_week = MaxVal(Price, 5);
	var min_month3s = MinVal(Price, 66);
	var max_month3s = MaxVal(Price, 66);
	var last = Price[0];
	var prevLast = Price[1];
	if(max_month3s < min_month3s * 1.21
		&& max_week > min_week && max_week < min_week * 1.11
		&& last > min_month3s
		&& last > prevLast
		&& max_month3s > min_week * 1.04){
		print(TO_LOG, "\n min_week %.2f,max_week %.2f,min_month3s %.2f,max_month3s %.2f,prevLast %.2f,last %.2f",
		    min_week, max_week, min_month3s, max_month3s, prevLast, last);
        enterLong(Lots, Entry, 0.08 * price(), 0.05 * price(), 0.08 * price());
    }
}