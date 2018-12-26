#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

struct Point
{
  int64_t x, y;
  Point(const int64_t &X, const int64_t &Y) : x(X), y(Y) {}
  Point() = default;
};

int64_t distance(const Point &a, const Point &b)
{
  return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

std::istream &operator>>(std::istream &is, Point &p)
{
  char c;
  is >> p.x >> c >> p.y;
  return is;
}

std::ostream &operator<<(std::ostream &os, Point &p)
{
  char c;
  os << p.x << ", " << p.y;
  return os;
}

size_t min_index(const size_t &invalid, const Point &point,
                 const std::vector<Point> &points)
{
  size_t result;
  int64_t min_dist(std::numeric_limits<int64_t>::max());
  for(size_t p = 0; p < points.size(); ++p)
    {
      int64_t d(distance(point, points[p]));
      if(min_dist > d)
        {
          min_dist = d;
          result = p;
        }
      else if(min_dist == d)
        {
          result = invalid;
        }
    }
  return result;
}

int main(int argc, char *argv[])
{
  std::ifstream infile(argv[1]);
  std::vector<Point> points(std::istream_iterator<Point>(infile), {});

  int64_t min_x(std::numeric_limits<int64_t>::max()), min_y(min_x),
    max_x(std::numeric_limits<int64_t>::min()), max_y(max_x);
  for(auto &p : points)
    {
      min_x = std::min(min_x, p.x);
      min_y = std::min(min_y, p.y);
      max_x = std::max(max_x, p.x);
      max_y = std::max(max_y, p.y);
    }

  int64_t width(max_x - min_x + 1), height(max_y - min_y + 1);
  const size_t invalid(points.size());
  std::vector<int64_t> num_claimed(points.size() + 1, 0);
  std::set<size_t> invalid_points;

  for(int64_t x = min_x; x <= max_x; ++x)
    {
      invalid_points.insert(min_index(invalid, Point(x, min_y), points));
      invalid_points.insert(min_index(invalid, Point(x, max_y), points));
    }
  for(int64_t y = min_y; y <= max_y; ++y)
    {
      invalid_points.insert(min_index(invalid, Point(min_x, y), points));
      invalid_points.insert(min_index(invalid, Point(max_x, y), points));
    }

  for(int64_t x = 0; x < width; ++x)
    for(int64_t y = 0; y < height; ++y)
      {
        int64_t min_dist(std::numeric_limits<int64_t>::max());
        size_t min_index;
        for(size_t p = 0; p < points.size(); ++p)
          {
            int64_t d(distance(Point(x + min_x, y + min_y), points[p]));
            if(min_dist > d)
              {
                min_dist = d;
                min_index = p;
              }
            else if(min_dist == d)
              {
                min_index = invalid;
              }
          }
        if(invalid_points.find(min_index) == invalid_points.end())
          ++num_claimed[min_index];
      }
  std::cout << "Part 1: "
            << *std::max_element(num_claimed.begin(), num_claimed.end())
            << "\n";

  int64_t area(0);
  constexpr int64_t cutoff(10000);
  const int64_t padding(cutoff / points.size() + 1);

  const int64_t x_lower(min_x - padding), x_upper(max_x + 1 + padding),
    y_lower(min_y - padding), y_upper(max_y + 1 + padding);
  for(int64_t x = x_lower; x < x_upper; ++x)
    for(int64_t y = y_lower; y < y_upper; ++y)
      {
        int64_t total_dist(0);
        for(auto &point : points)
          {
            total_dist += distance(Point(x, y), point);
            if(total_dist > cutoff)
              break;
          }
        if(total_dist < cutoff)
          ++area;
      }
  std::cout << "Part 2: " << area << "\n";
}