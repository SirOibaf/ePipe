/*
 * Copyright (C) 2016 Hops.io
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
 * File:   common.h
 * Author: Mahmoud Ismail<maism@kth.se>
 *
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <NdbApi.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/pthread/mutex.hpp>
#include <boost/thread/pthread/condition_variable_fwd.hpp>
#include <boost/unordered/unordered_set.hpp>
#include <boost/unordered/unordered_map.hpp>
#include "vector"
#include "Logger.h"

using namespace std;

typedef boost::unordered_set<int> UISet;
typedef boost::unordered_map<int, int> UIMap;

//Constansts

#define RETRIES 5
#define DELAY_BETWEEN_RETRIES 3
#define VERBOSE 0
#define WAIT_UNTIL_READY 30
#define DEFAULT_MAX_CAPACITY 10000

enum MetadataType{
    Schemabased = 0,
    Schemaless = 1,
    Both = 2
};

enum OperationType{
    Add = 0,
    Delete = 1,
    Update = 2,
};

enum OpsLogOn{
    Dataset = 0,
    Project = 1,
    Schema = 2
};

struct TableUnitConf {
    int mWaitTime;
    int mBatchSize;
    int mNumReaders;

    TableUnitConf(int wait_time, int batch_size, int num_readers) {
        mWaitTime = wait_time;
        mBatchSize = batch_size;
        mNumReaders = num_readers;
    }

    vector<int> getVector() {
        vector<int> d;
        d.push_back(mWaitTime);
        d.push_back(mBatchSize);
        d.push_back(mNumReaders);
        return d;
    }

    void update(vector<int> v) {
        if (v.size() == 3) {
            mWaitTime = v[0];
            mBatchSize = v[1];
            mNumReaders = v[2];
        }
    }

    string getString() {
        stringstream str;
        str << mWaitTime << " " << mBatchSize << " " << mNumReaders;
        return str.str();
    }
};


#endif /* COMMON_H */
