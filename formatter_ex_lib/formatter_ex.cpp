#include "formatter_ex.h"

#include "/home/debain/kostrub1n/workspace/projects/lab03/formatter_lib/formatter.h"

std::ostream& formatter(std::ostream& out, const std::string& message)
{
    return out << formatter(message);
}
