cmake_minimum_required(VERSION 3.24)
project(oop)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop main.cpp Field.cpp Field.h Controller.cpp Controller.h Mediator.cpp Mediator.h CommandReader.cpp CommandReader.h Move.cpp Move.h FieldView.cpp FieldView.h CellView.cpp CellView.h Cell.cpp Cell.h ConsolePlayer.cpp ConsolePlayer.h PlayerInteface.h
        ./Events/Event.h ./Events/EventPlayer.h ./Events/EventField.h ./Events/EventHealth.h ./Events/EventSub.h
        ./Events/EventKey.h ./Events/EventLock.h ./Events/EventWin.h Logging/ConsoleLogger.cpp Logging/ConsoleLogger.h Logging/FileLogger.cpp Logging/FileLogger.h Observable/ConcreteObservable.cpp Observable/ConcreteObservable.h Observable/Observable.h Observer/ConcreteObserver.cpp Observer/ConcreteObserver.h Observer/Observer.h Logging/Logger.h Logging/Message.h Logging/Level.h Settings/FileMove.cpp Settings/FileMove.h Settings/GetMove.h Settings/Parser/TranslateFile.cpp Settings/Parser/TranslateFile.h Rules/GenWithLock.h Rules/GenPlayer.h Rules/GenWinRule.h Rules/GenLockEvent.h Rules/GenUnlockEvent.h Rules/GenKeyEvent.h Rules/GenChangeHealthEvent.h Rules/GeneratorRules.h)
