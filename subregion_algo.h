// Subregion Algorithms
//
// Copyright (C) 2003-2008 Jeffrey S. Perry
//
// This program is free software: you can redistribute it
// and/or modify it under the terms of the GNU General
// Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your
// option) any later version.
//
// This program is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A
// PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public
// License along with this program.  If not, see
// <http://www.gnu.org/licenses/>.
//
// contact: jeffsp@gmail.com

#ifndef SUBREGION_ALGO_HPP
#define SUBREGION_ALGO_HPP

#include "subregion_iter.h"
#include <cstring>

namespace jack_rabbit
{

/// @brief Overload for fast subregion copies
///
/// This implementation of copy may be faster than std::copy.
template<class T>
inline subregion_iter<T>
copy (const subregion_iter<T> &src1,
    const subregion_iter<T> &src2,
    subregion_iter<T> dest)
{
    // Copy one row at a time
    for (subregion_iter<T> current_src = src1;
        current_src != src2;
        current_src.next_row ())
    {
        typename subregion_iter<T>::pointer dest_p = &*dest.row_begin ();
        typename subregion_iter<T>::pointer src_p = &*current_src.row_begin ();
        std::memmove (dest_p,
            src_p,
            sizeof (typename subregion_iter<T>::value_type)
            * (current_src.row_end () - current_src.row_begin ()));
        dest.next_row ();
    }
    return src2;
}

} // namespace jack_rabbit

#endif // SUBREGION_ALGO_HPP
