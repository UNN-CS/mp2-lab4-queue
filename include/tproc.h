class TProc {
private:
	double q2;
	bool isBusy = false;
public:
	TProc(double q = 0.5);
	const bool IsBusy();
	bool JobHasDone();
	void SetBusy(bool b);

};
