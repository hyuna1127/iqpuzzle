/**
 * \file highscore.h
 *
 * \section LICENSE
 *
 * Copyright (C) 2012-2019 Thorsten Roth <elthoro@gmx.de>
 *
 * This file is part of iQPuzzle.
 *
 * iQPuzzle is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * iQPuzzle is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with iQPuzzle.  If not, see <http://www.gnu.org/licenses/>.
 *
 * \section DESCRIPTION
 * Class definition for highscore.
 */

#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

#include <QObject>
#include <QSettings>
#include <QTime>

/**
 * \class Highscore
 * \brief Generating and showing highscore.
 */
class Highscore : public QObject {
  Q_OBJECT

 public:
    explicit Highscore(QWidget *pParent = nullptr,
                       QObject *pParentObj = nullptr);

 public slots:
    void showHighscore(const QString &sBoard);
    void checkHighscore(const QString &sBoard, const quint32 nMoves,
                        const QTime tTime);

 private:
    QStringList readHighscore(const QString &sBoard, const QString &sKey) const;
    void insertHighscore(const QString &sBoard, const quint8 nPosition,
                         const quint32 nMoves, const QTime tTime);

    QWidget *m_pParent;
    QSettings *m_pHighscore;
    const quint8 m_nMAXPOS;
};

#endif  // HIGHSCORE_H_
