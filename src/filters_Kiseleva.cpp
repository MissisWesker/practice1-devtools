#include "filters.hpp"

class FiltersKiseleva : public Filters
{
public:
   virtual void boxFilter(const Matrix &src, Matrix& dst, const int kSize = 3)
   {
	   for (int i = 0; i < src.rows(); i++)
		   for (int j = 0; j < src.cols(); j++)
		   {
			   unsigned val = 0;
			   for (int s = i - kSize / 2; s <= i + kSize / 2; s++)
				   for (int t = j - kSize / 2; t <= j + kSize / 2; t++)
					   val = val + src[i][j];
			   val = val/(kSize*kSize);
			   dst[i][j] = val;
		   }
   }

   virtual void filter2d(const Matrix &src, Matrix& dst, const Matrix &kernel)
   {
   }
   virtual void median(const Matrix &src, Matrix &dst, const int kSize = 3)
   { 
   }
   virtual void SobelOx(const Matrix &src, Matrix &dst)
   { 
   }

};

Filters* createFiltersKiseleva()
{
   Filters* filters = new FiltersKiseleva();
   return filters;
}
