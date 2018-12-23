class TJobStream
{
public:

	double q1;
	int job_number = 0;

	TJobStream(double q = 0.5);
	bool IsNewJob();
	int GetNumberOfJobs() const;
};