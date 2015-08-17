#include "filters.hpp"

Filters* createFiltersOpenCV();
Filters* createFiltersKiseleva();

Filters* createFilters(FILTERS_IMPLEMENTATIONS impl)
{
    switch (impl) {
        case OPENCV:
            return createFiltersOpenCV();
		case KISELEVA:
			return createFiltersKiseleva();
        default:
            return 0;
    }
}
