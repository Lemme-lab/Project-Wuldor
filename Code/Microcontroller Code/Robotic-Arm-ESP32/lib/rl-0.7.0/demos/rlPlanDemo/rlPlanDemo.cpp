//
// Copyright (c) 2009, Markus Rickert
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#include <QApplication>
#include <QMetaType>
#include <QMessageBox>
#include <stdexcept>
#include <string>
#include <rl/math/Transform.h>
#include <rl/math/Vector.h>
#include <rl/plan/VectorList.h>

#include "MainWindow.h"

MainWindow* MainWindow::singleton = nullptr;

int
main(int argc, char** argv)
{
	try
	{
		QApplication application(argc, argv);
		
		qRegisterMetaType<rl::math::Real>("rl::math::Real");
		qRegisterMetaType<rl::math::Transform>("rl::math::Transform");
		qRegisterMetaType<rl::math::Vector>("rl::math::Vector");
		qRegisterMetaType<rl::plan::VectorList>("rl::plan::VectorList");
		qRegisterMetaType<std::string>("std::string");
		
		QObject::connect(&application, SIGNAL(lastWindowClosed()), &application, SLOT(quit()));
		
		MainWindow::instance()->show();
		
		return application.exec();
	}
	catch (const std::exception& e)
	{
		QApplication application(argc, argv);
		QMessageBox::critical(nullptr, "Error", e.what());
		return EXIT_FAILURE;
	}
}
