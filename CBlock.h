/**
 * \file CBlock.cpp
 *
 * \section LICENSE
 *
 * Copyright (C) 2012-2014 Thorsten Roth <elthoro@gmx.de>
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
 */

#ifndef IQPUZZLE_CBLOCK_H_
#define IQPUZZLE_CBLOCK_H_

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QPainter>

class CBlock : public QGraphicsItem {
  public:
    CBlock(const quint16 nID, QPolygonF shape, QBrush bgcolor, QPen border,
           quint16 nGrid, QList<CBlock *> *pListBlocks,
           QPointF posTopLeft = QPoint(0, 0),
           const bool bBarrier = false);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    QPointF getPosition() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);

    void moveBlockGrid(const QPointF pos);
    void setNewZValue(qint16 nZ);
    void rescaleBlock(quint16 nNewScale);
    quint16 getIndex() const;
    enum { Type = UserType + 1 };

  protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *p_Event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *p_Event);
    void wheelEvent(QGraphicsSceneWheelEvent *p_Event);
    int type() const;

  private:
    QPointF snapToGrid(const QPointF point) const;

    const quint16 m_nID;
    QPolygonF m_PolyShape;
    QBrush m_bgBrush;
    QPen m_borderPen;
    quint16 m_nGrid;
    QList<CBlock *> *m_pListBlocks;
    bool m_bBarrier;
    bool m_bMousePressed;

    QTransform *m_pTransform;
    QPointF m_posBlockSelected;
    QGraphicsSimpleTextItem m_ItemNumberText;
};

#endif  // IQPUZZLE_CBLOCK_H_