/*
    SPDX-FileCopyrightText: 2008 Michael Jansen <kde@michael-jansen.biz>
    SPDX-FileCopyrightText: 2016 Marco Martin <mart@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KSERVICEACTIONCOMPONENT_H
#define KSERVICEACTIONCOMPONENT_H

#include "component.h"

#include <KService>

#include <memory>

/**
 * @author Michael Jansen <kde@michael-jansen.biz>
 */
class KServiceActionComponent : public Component
{
    Q_OBJECT

public:
    //! Creates a new component. The component will be registered with @p
    //! registry if specified and registered with dbus.
    KServiceActionComponent(const QString &serviceStorageId, const QString &friendlyName, GlobalShortcutsRegistry *registry = nullptr);

    ~KServiceActionComponent() override;

    void loadFromService();
    void emitGlobalShortcutPressed(const GlobalShortcut &shortcut) override;

    bool cleanUp() override;

private:
    void runService(const QString &token);
    void runServiceAction(const KServiceAction &action, const QString &token);
    void startDetachedWithToken(const QString &program, const QStringList &args, const QString &token);
    bool runWithKLauncher(const QString &command, QStringList &args);

    QString m_serviceStorageId;
    bool m_isInApplicationsDir = false;
    KService::Ptr m_service;
};

#endif /* #ifndef COMPONENT_H */
