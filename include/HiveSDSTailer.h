/*
 * Copyright (C) 2017 Hops.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/*
 * File:   HiveSDSTailer.h
 * Author: Fabio Buso <buso@kth.se>
 *
 */

#ifndef HIVESDSTAILER_H
#define HIVESDSTAILER_H

#include "Cleaner.h"

class HiveSDSTailer : public Cleaner{
public:
    HiveSDSTailer(Ndb* ndb, const int poll_maxTimeToWait);
    virtual ~HiveSDSTailer();
protected:
    static const WatchTable TABLE;
    virtual void handleEvent(NdbDictionary::Event::TableEvent eventType, NdbRecAttr* preValue[], NdbRecAttr* value[]);
};

#endif /* HIVESDSTAILER_H */
