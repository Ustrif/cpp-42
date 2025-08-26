#ifndef __FIXED__
#define __FIXED__

#include <ostream>

class Fixed
{
	private:
		int	fpVal;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

};

std::ostream& operator<<(std::ostream &out, const Fixed &f);

#endif //__FIXED__