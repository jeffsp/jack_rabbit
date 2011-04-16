// Foveate View
//
// Copyright (C) 2008
// Center for Perceptual Systems
// University of Texas at Austin
//
// jsp Tue Mar 25 10:55:03 CDT 2008

#ifndef FOVEATE_VIEW_H
#define FOVEATE_VIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <iostream>

namespace jack_rabbit
{

class FoveateView : public QGraphicsView
{
    Q_OBJECT

    public:
    FoveateView (QWidget *parent = 0) : QGraphicsView (parent)
    {
    }
    private:
};

} // namespace jack_rabbit

#endif // FOVEATE_VIEW_H
