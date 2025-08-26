#ifndef __FIXED__
#define __FIXED__

class Fixed
{
	private:
		int	fpVal;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif //__FIXED__