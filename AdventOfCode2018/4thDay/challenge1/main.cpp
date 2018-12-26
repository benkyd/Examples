#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>

enum class State {begin, sleep, awaken};
struct Action
{
  State state;
  int64_t guard_id;
};

struct Event
{
  int64_t month, day, hour, minute;
  Action action;
};


std::istream &operator>>(std::istream &is, Action &action)
{
  std::string element;
  is >> element;
  if(element=="Guard")
    {
      action.state=State::begin;
      char c;
      is >> c >> action.guard_id;
    }
  else if(element=="falls")
    {
      action.state=State::sleep;
    }
  else if(element=="wakes")
    {
      action.state=State::awaken;
    }
  else
    {
      throw std::runtime_error("Invalid input");
    }
  std::getline(is,element);
  return is;
}

std::istream &operator>>(std::istream &is, Event &event)
{
  char c;
  int64_t year;
  is >> c;
  if(is.good())
    {
      is >> year >> c >> event.month >> c >> event.day
         >> event.hour >> c >> event.minute >> c
         >> event.action;

      if(event.hour==23)
        {
          event.minute=0;
        }
    }
  return is;
}



std::ostream &operator<<(std::ostream &os, const Action &action)
{
  switch(action.state)
    {
    case State::begin:
      os << "Guard #" << action.guard_id << " begins shift";
      break;
    case State::sleep:
      os << "falls asleep";
      break;
    case State::awaken:
      os << "wakes up";
      break;
    default:
      os << "What?";
      break;
    }
  return os;
}

std::ostream &operator<<(std::ostream &os, const Event &event)
{
  os << "[1518-"
     << std::setw(2) << std::setfill('0') << event.month << "-"
     << std::setw(2) << std::setfill('0') << event.day << " "
     << std::setw(2) << std::setfill('0') << event.hour << ":"
     << std::setw(2) << std::setfill('0') << event.minute << "] "
     << event.action;
  return os;
}

std::pair<int64_t,int64_t> max_incident(const std::vector<std::pair<int64_t,
                                        int64_t>> &incidents)
{
  std::vector<int64_t> sleep_incidents(60,0);
  for(auto &times: incidents)
    {
      for(size_t time=times.first; time<times.second; ++time)
        { ++(sleep_incidents[time]); }
    }

  int64_t max_incidents(0), max_minute(0);
  for(size_t time=0; time<sleep_incidents.size(); ++time)
    {
      if(max_incidents<sleep_incidents[time])
        {
          max_incidents=sleep_incidents[time];
          max_minute=time;
        }
    }
  return std::make_pair(max_incidents,max_minute);
}


int main(int argc, char *argv[])
{
  std::ifstream infile(argv[1]);
  std::vector<Event> events(std::istream_iterator<Event>(infile), {});

  std::map<int,std::vector<std::pair<int64_t,int64_t>>> guards;

  int64_t guard_id;
  int64_t start(-1);
  for(auto &event: events)
    {
      switch(event.action.state)
        {
        case State::begin:
          guard_id=event.action.guard_id;
          break;
        case State::sleep:
          start=event.minute;
          break;
        case State::awaken:
          guards[guard_id].emplace_back(start,event.minute);
          break;
        }
    }

  int64_t max_time_guard, max_time(0);
  for(auto &guard: guards)
    {
      int64_t total_time(0);
      for(auto &time: guard.second)
        {
          total_time+=time.second-time.first;
        }
      if(total_time>max_time)
        {
          max_time_guard=guard.first;
          max_time=total_time;
        }
    }

  auto [max_incidents,max_minute]=max_incident(guards[max_time_guard]);
  std::cout << "Part 1: " << (max_minute*max_time_guard) << "\n";

  std::vector<int64_t> num_incidents(guards.size());
  int64_t max_guard_incidents(0), max_guard_minute(0), max_guard_id(-1);
  for(auto &guard: guards)
    {
      auto [incidents,minute]=max_incident(guard.second);
      if(incidents>max_guard_incidents)
        {
          max_guard_incidents=incidents;
          max_guard_minute=minute;
          max_guard_id=guard.first;
        }
    }
  std::cout << "Part 2: " << (max_guard_id * max_guard_minute) << "\n";
}