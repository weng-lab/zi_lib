//
// Copyright (C) 2010  Aleksandar Zlateski <zlateski@mit.edu>
// ----------------------------------------------------------
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef ZI_ZARGS_DETAIL_STRING_UTILS_HPP
#define ZI_ZARGS_DETAIL_STRING_UTILS_HPP 1

#include <string>
#include <cstddef>
#include <cstdlib>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/join.hpp>

namespace zi {
namespace zargs_ {
namespace detail {

inline std::string to_lower( const std::string& s )
{
    return boost::algorithm::to_lower_copy(s);
}

template< class Container >
inline void explode( Container &ret, const std::string& source, char splitter = ' ' )
{
    boost::split(ret, source, std::bind2nd(std::equal_to<char>(), splitter));
}

inline bool begins_with( const std::string &b, const std::string &s )
{
    return boost::starts_with(s, b);
}

inline std::string strip_quotes( const std::string& s )
{
    std::size_t len = s.size();

    if (len < 2)
    {
        return s;
    }

    if ( ( s[0] == '"'  && s[ len - 1 ] == '"' ) ||
         ( s[0] == '\'' && s[ len - 1 ] == '\'') )
    {
        std::string ret( s.begin() + 1, s.end() - 1 );
        return ret;
    }

    return s;
}


} // namespace detail
} // namespace zargs_
} // namespace zi

#endif
