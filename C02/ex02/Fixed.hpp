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
		~Fixed();
		Fixed &operator=(const Fixed &other);
		Fixed operator + (const Fixed &other);
		Fixed operator - (const Fixed &other);
		Fixed operator / (const Fixed &other);
		Fixed operator * (const Fixed &other);
		Fixed operator ++ ();
		Fixed operator ++ (int);
		Fixed operator -- ();
		Fixed operator -- (int);
		bool operator > (const Fixed &other) const;
		bool operator < (const Fixed &other) const;
		bool operator >= (const Fixed &other) const;
		bool operator <= (const Fixed &other) const;
		bool operator == (const Fixed &other) const;
		bool operator != (const Fixed &other) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static Fixed& min(Fixed &num1, Fixed &num2);
		static const Fixed& min(const Fixed &num1, const Fixed &num2);
		static Fixed& max(Fixed &num1, Fixed &num2);
		static const Fixed& max(const Fixed &num1, const Fixed &num2);
};

std::ostream& operator<<(std::ostream &out, const Fixed &f);

#endif //__FIXED__