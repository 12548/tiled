/*
 * createobjecttool.h
 * Copyright 2010, Thorbjørn Lindeijer <thorbjorn@lindeijer.nl>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CREATEOBJECTTOOL_H
#define CREATEOBJECTTOOL_H

#include "abstracttool.h"

namespace Tiled {

class MapObject;
class ObjectGroup;

namespace Internal {

class MapObjectItem;

class CreateObjectTool : public AbstractTool
{
public:
    CreateObjectTool(QObject *parent = 0);

    void enable(MapScene *scene);
    void disable();

    void mouseEntered();
    void mouseLeft();
    void mouseMoved(const QPointF &pos,
                    Qt::KeyboardModifiers modifiers);
    void mousePressed(const QPointF &pos,
                      Qt::MouseButton button,
                      Qt::KeyboardModifiers modifiers);
    void mouseReleased(const QPointF &pos,
                       Qt::MouseButton button);

    void languageChanged();

private:
    void startNewMapObject(const QPointF &pos, ObjectGroup *objectGroup);
    MapObject *clearNewMapObjectItem();
    void cancelNewMapObject();
    void finishNewMapObject();

    ObjectGroup *currentObjectGroup() const;

    MapScene *mMapScene;
    MapObjectItem *mNewMapObjectItem;
};

} // namespace Internal
} // namespace Tiled

#endif // CREATEOBJECTTOOL_H
