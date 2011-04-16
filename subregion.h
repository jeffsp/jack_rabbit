// Rectangular Raster Subregion
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

#ifndef SUBREGION_HPP
#define SUBREGION_HPP

#include <cstddef>

namespace jack_rabbit
{

/// @brief Rectangular subregion
struct subregion
{
    /// @brief Subscript of starting element
    size_t r;
    /// @brief Subscript of starting element
    size_t c;
    /// @brief Dimensions of the subregion
    size_t rows;
    /// @brief Dimensions of the subregion
    size_t cols;
};

} // namespace jack_rabbit

#endif // SUBREGION_HPP
