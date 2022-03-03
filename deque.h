class deque
{
private:
	float* mass;
	int tail;
	int head;
	int size;
public:
	explicit deque(int);
	deque(const deque&);
	~deque();
	void display() const;
	bool empty() const;
	void push_back(float);
	float pop_back();
	void push_front(float var);
	float pop_front();
	deque& operator=(const deque&);
	deque operator !() const;
	deque& operator ++();
	deque& operator --();
	friend deque& operator--(deque&, int);
	friend deque& operator++(deque&, int);
};