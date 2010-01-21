/*
 * Copyright (C) 2009 Nicolas Bonnefon and other contributors
 *
 * This file is part of glogg.
 *
 * glogg is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * glogg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with glogg.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ABSTRACTLOGDATA_H
#define ABSTRACTLOGDATA_H

#include <QObject>
#include <QString>
#include <QStringList>

// Base class representing a set of data.
// It can be either a full set or a filtered set.
class AbstractLogData : public QObject {
  Q_OBJECT

  public:
    AbstractLogData();
    // Permit each child to have its destructor
    virtual ~AbstractLogData() {};

    // Returns the line passed as a QString
    QString getLineString( int line ) const;
    // Returns a set of lines as a QStringList
    QStringList getLines( int first_line, int number ) const;
    // Returns the total number of lines
    int getNbLine() const;
    // Returns the length of the longest line
    int getMaxLength() const;

  protected:
    // Internal function called to get a given line
    virtual QString doGetLineString( int line ) const = 0;
    // Internal function called to get a set of lines
    virtual QStringList doGetLines( int first_line, int number ) const = 0;
    // Internal function called to get the number of lines
    virtual int doGetNbLine() const = 0;
    // Internal function called to get the maximum length
    virtual int doGetMaxLength() const = 0;
};

#endif
