
class Dollar
{
	public:
		Dollar(int amount){
			_amount = amount;
		};

		void times(int multiplier){
			_amount = _amount * multiplier; // $5 X 2 = $10 
		};
		int _amount;

	// private:
};