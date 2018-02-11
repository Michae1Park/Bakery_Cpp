#include <iostream>
#include <vector>
#include <unordered_map>

class Subject {
public:
	virtual void registerObserver(Observer o) = 0;
	virtual void unregisterObserver(Observer o) = 0;
	virtual void notifyObservers() = 0;
};

class BakeryInventory : Subject {
private:
	std::unordered_map<Bread, int> items;
	std::vector<Observer> observerList;

public: 
	void registerObserver(Observer o) {
		observerList.push_back(o);
	}
	void unregisterObserver(Observer o) {
		observerList.remove(observerList.indexOf(o));
	}

	void notifyObservers() {
		for (Iterator<Observer> it = observerList.iterator(); it.hasNext();)
		{
			Observer o = it.next();
			o.update(runs, wickets, overs);
		}
	}

	void dataChanged() {
		//get latest data
		runs = getLatestRuns();
		wickets = getLatestWickets();
		overs = getLatestOvers();

		notifyObservers();
	}
};

// This interface is implemented by all those
// classes that are to be updated whenever there
// is an update from CricketData

class Observer {
public:
	virtual void update(int runs, int wickets, float overs) = 0;
};

class NumBreadDisplay : Observer {
private:
	int runs, wickets;
	float overs;

public:
	void update(int runs, int wickets, float overs) {
		runs = runs;
		wickets = wickets;
		overs = overs;
		display();
	}

	void display() {
		std::cout << "runs: " + runs << std::endl;
	}
};

// Driver Class
class Main
{
	public static void main(String args[])
	{
		// create objects for testing
		AverageScoreDisplay averageScoreDisplay =
			new AverageScoreDisplay();
		CurrentScoreDisplay currentScoreDisplay =
			new CurrentScoreDisplay();

		// pass the displays to Cricket data
		CricketData cricketData = new CricketData();

		// register display elements
		cricketData.registerObserver(averageScoreDisplay);
		cricketData.registerObserver(currentScoreDisplay);

		// in real app you would have some logic to
		// call this function when data changes
		cricketData.dataChanged();

		//remove an observer
		cricketData.unregisterObserver(averageScoreDisplay);

		// now only currentScoreDisplay gets the
		// notification
		cricketData.dataChanged();
	}
}