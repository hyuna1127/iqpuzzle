/**
 * \file block.h
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
 * Class definition for a block.
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include <QGraphicsObject>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QPainter>

#include "./settings.h"

/**
 * \class Block
 * \brief Block handling (move, rotate, collision check).
 */
class Block : public QGraphicsObject {
  Q_OBJECT

 public:
    Block(const quint16 nID, QPolygonF shape, QBrush bgcolor, QPen border,
          quint16 nGrid, QList<Block *> *pListBlocks, Settings *pSettings,
          QPointF posTopLeft = QPoint(0, 0), const bool bBarrier = false);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    QPointF getPosition() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    void setBrushStyle(Qt::BrushStyle style);

    QPolygonF getPolygon() const;
    void setNewZValue(const double nZ);
    void rescaleBlock(const quint16 nNewScale);
    quint16 getIndex() const;
    enum { Type = UserType + 1 };

 signals:
    void incrementMoves();
    void checkPuzzleSolved();

 protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *p_Event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *p_Event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *p_Event);
    void wheelEvent(QGraphicsSceneWheelEvent *p_Event);
    int type() const;

 private:
    void moveBlockGrid(const QPointF pos);
    bool checkCollision(const QPainterPath &thisPath);
    void checkBlockIntersection();
    QPointF snapToGrid(const QPointF point) const;
    void resetBrushStyle() const;

    void moveBlock(const bool bRelease = false);
    void rotateBlock(const int nDelta = -1);
    void flipBlock();

    const quint16 m_nID;
    QPolygonF m_PolyShape;
    QBrush m_bgBrush;
    QPen m_borderPen;
    quint16 m_nGrid;
    QList<Block *> *m_pListBlocks;
    Settings *m_pSettings;
    bool m_bActive;
    QPixmap m_CollTexture;

    QTransform *m_pTransform;
    QPointF m_posBlockSelected;
    QPointF m_posMouseSelected;
    QGraphicsSimpleTextItem m_ItemNumberText;
};

#endif  // BLOCK_H_
