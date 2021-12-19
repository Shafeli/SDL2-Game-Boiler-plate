#pragma once

#include <memory>
#include <stack>
#include "State.h"

namespace Machine
{
    using StateRef = std::unique_ptr<State>;
}
class StateMachine
{
private:
    std::stack<Machine::StateRef> m_states;
    Machine::StateRef m_newState;

    bool m_isRemoving = false;
    bool m_isAdding = false;
    bool m_isReplacing = false;

public:

    void AddState(Machine::StateRef newState, bool isReplacing = true);
    void RemoveState();
    void ProcessStateChanges();
    Machine::StateRef& GetActiveState();


};

