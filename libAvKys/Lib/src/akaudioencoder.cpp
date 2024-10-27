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

#include "akaudioencoder.h"

class AkAudioEncoderPrivate
{
    public:
        int m_bitrate {128000};
};

AkAudioEncoder::AkAudioEncoder(QObject *parent):
    AkElement{parent}
{
    this->d = new AkAudioEncoderPrivate();
}

AkAudioEncoder::~AkAudioEncoder()
{
    delete this->d;
}

int AkAudioEncoder::bitrate() const
{
    return this->d->m_bitrate;
}

QVariantList AkAudioEncoder::controls() const
{
    return {};
}

bool AkAudioEncoder::setControls(const QVariantMap &controls)
{
    Q_UNUSED(controls)

    return false;
}

void AkAudioEncoder::setBitrate(int bitrate)
{
    if (this->d->m_bitrate == bitrate)
        return;

    this->d->m_bitrate = bitrate;
    emit this->bitrateChanged(bitrate);
}

void AkAudioEncoder::resetBitrate()
{
    this->setBitrate(128000);
}

#include "moc_akaudioencoder.cpp"
