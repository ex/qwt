/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtWidgets module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QOPENGLWIDGET_H
#define QOPENGLWIDGET_H

#include <QtWidgets/qtwidgetsglobal.h>

#ifndef QT_NO_OPENGL

#include <QtWidgets/QWidget>
#include <QtGui/QSurfaceFormat>
#include <QtGui/qopengl.h>

QT_BEGIN_NAMESPACE

class QOpenGLWidgetPrivate;

class Q_WIDGETS_EXPORT QOpenGLWidget : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(QOpenGLWidget)

public:
    enum UpdateBehavior {
        NoPartialUpdate,
        PartialUpdate
    };

    explicit QOpenGLWidget(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~QOpenGLWidget();

    void setUpdateBehavior(UpdateBehavior updateBehavior);
    UpdateBehavior updateBehavior() const;

    void setFormat(const QSurfaceFormat &format);
    QSurfaceFormat format() const;

    GLenum textureFormat() const;
    void setTextureFormat(GLenum texFormat);

    bool isValid() const;

    void makeCurrent();
    void doneCurrent();

    QOpenGLContext *context() const;
    GLuint defaultFramebufferObject() const;

    QImage grabFramebuffer();

Q_SIGNALS:
    void aboutToCompose();
    void frameSwapped();
    void aboutToResize();
    void resized();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

    void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *e) Q_DECL_OVERRIDE;
    bool event(QEvent *e) Q_DECL_OVERRIDE;

    int metric(QPaintDevice::PaintDeviceMetric metric) const Q_DECL_OVERRIDE;
    QPaintDevice *redirected(QPoint *p) const Q_DECL_OVERRIDE;
    QPaintEngine *paintEngine() const Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(QOpenGLWidget)
};

QT_END_NAMESPACE

#endif // QT_NO_OPENGL

#endif // QOPENGLWIDGET_H
