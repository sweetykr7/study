
class Dollar
{
	public:
		Dollar(int amount){
			_amount = amount;
		};

		Dollar times(int multiplier){
			// _amount = _amount * multiplier; // $5 X 2 = $10 
			return Dollar(_amount * multiplier); // Dollar 부작용?
		};
		int _amount;

	// private:
};