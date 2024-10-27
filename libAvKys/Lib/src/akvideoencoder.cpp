/* Webcamoid, webcam capture application.
 * Copyright (C) 2024  Gonzalo Exequiel Pedone
 *
 * Webcamoid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamoid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
 *
 * Web-Site: http://webcamoid.github.io/
 */

#include <QVariant>

#include "akvideoencoder.h"

class AkVideoEncoderPrivate
{
    public:
        int m_bitrate {1500000};
        int m_gop {1000};
};

AkVideoEncoder::AkVideoEncoder(QObject *parent):
    AkElement{parent}
{
    this->d = new AkVideoEncoderPrivate();
}

AkVideoEncoder::~AkVideoEncoder()
{
    delete this->d;
}

int AkVideoEncoder::bitrate() const
{
    return this->d->m_bitrate;
}

int AkVideoEncoder::gop() const
{
    return this->d->m_gop;
}

QVariantList AkVideoEncoder::controls() const
{
    return {};
}

bool AkVideoEncoder::setControls(const QVariantMap &controls)
{
    Q_UNUSED(controls)

    return false;
}

void AkVideoEncoder::setBitrate(int bitrate)
{
    if (this->d->m_bitrate == bitrate)
        return;

    this->d->m_bitrate = bitrate;
    emit this->bitrateChanged(bitrate);
}

void AkVideoEncoder::setGop(int gop)
{
    if (this->d->m_gop == gop)
        return;

    this->d->m_gop = gop;
    emit this->gopChanged(gop);
}

void AkVideoEncoder::resetBitrate()
{
    this->setBitrate(1500000);
}

void AkVideoEncoder::resetGop()
{
    this->setGop(1000);
}

#include "moc_akvideoencoder.cpp"
