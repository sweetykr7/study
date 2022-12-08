
class Dollar
{
	public:
		Dollar(int amount){
			_amount = amount;
		};

		Dollar times(int multiplier){
			_amount = _amount * multiplier; // $5 X 2 = $10 
			return NULL;
		};
		int _amount;

	// private:
};