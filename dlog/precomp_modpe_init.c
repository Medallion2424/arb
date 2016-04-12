/*=============================================================================

    This file is part of ARB.

    ARB is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    ARB is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ARB; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2016 Pascal Molin

******************************************************************************/

#include "dlog.h"

/* log mod p^e */
void
dlog_precomp_modpe_init(dlog_precomp_t pre, ulong a, ulong p, ulong e, ulong pe, ulong num)
{
    if ( pe < DLOG_TABLE_MODPE_LIM )
    {
        dlog_precomp_small_init(pre, a, pe, pe - pe / p, num);
        return;
    }
    else {
        if (e > 1)
        {
            pre->type = DLOG_MODPE;
            pre->cost = dlog_modpe_init(pre->t.modpe, a, p, e, pe, num);
        }
        else
        {
            dlog_precomp_n_init(pre, a, p, p - 1, num);
        }
    }
}