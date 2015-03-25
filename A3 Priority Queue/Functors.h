#ifndef _GREATERTHAN_H
#define _GREATERTHAN_H

//greater than comparison
template<class T>
class greaterThan
{
public:
	bool operator()(const T& t_left, const T& t_right) const
	{
		return (t_left > t_right);
	}
};
#endif

#ifndef _LESSTHAN_H
#define _LESSTHAN_H

//less than comparison
template<class T>
class lessThan
{
public:
	bool operator()(const T& t_left, const T& t_right) const
	{
		return (t_left < t_right);
	}
};
#endif 
