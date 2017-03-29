#include "translator.h"

using namespace XCSP3Core;

template <class T>
void displayList(vector<T>& list, string separator = " ")
{
        if (list.size() > 8) {
                for (int i = 0; i < 3; i++)
                        cout << list[i] << separator;
                cout << " ... ";
                for (int i = list.size() - 4; i < list.size(); i++)
                        cout << list[i] << separator;
                cout << endl;
                return;
        }
        for (int i = 0; i < list.size(); i++)
                cout << list[i] << separator;
        cout << endl;
}

void displayList(vector<XVariable*>& list, string separator = " ")
{
        if (list.size() > 8) {
                for (int i = 0; i < 3; i++)
                        cout << list[i]->id << separator;
                cout << " ... ";
                for (unsigned int i = list.size() - 4; i < list.size(); i++)
                        cout << list[i]->id << separator;
                cout << endl;
                return;
        }
        for (unsigned int i = 0; i < list.size(); i++)
                cout << list[i]->id << separator;
        cout << endl;
}

void Xcsp3_to_Naxos::beginInstance(InstanceType type)
{
        cout << "Start Instance - type=" << type << endl;
}

void Xcsp3_to_Naxos::endInstance()
{
        cout << "End SAX parsing " << endl;
}

void Xcsp3_to_Naxos::beginVariables()
{
        cout << " start variables declaration" << endl;
}

void Xcsp3_to_Naxos::endVariables()
{
        cout << " end variables declaration" << endl << endl;
}

void Xcsp3_to_Naxos::beginVariableArray(string id)
{
        cout << "    array: " << id << endl;
}

void Xcsp3_to_Naxos::endVariableArray()
{
}

void Xcsp3_to_Naxos::beginConstraints()
{
        cout << " start constraints declaration" << endl;
}

void Xcsp3_to_Naxos::endConstraints()
{
        cout << "\n end constraints declaration" << endl << endl;
}

void Xcsp3_to_Naxos::beginGroup(string id)
{
        cout << "   start group of constraint " << id << endl;
}

void Xcsp3_to_Naxos::endGroup()
{
        cout << "   end group of constraint" << endl;
}

void Xcsp3_to_Naxos::beginBlock(string classes)
{
        cout << "   start block of constraint classes = " << classes << endl;
}

void Xcsp3_to_Naxos::endBlock()
{
        cout << "   end group of constraint" << endl;
}

void Xcsp3_to_Naxos::beginSlide(string id, bool circular)
{
        cout << "   start slide " << id << endl;
}

void Xcsp3_to_Naxos::endSlide()
{
        cout << "   end slide" << endl;
}

void Xcsp3_to_Naxos::beginObjectives()
{
        cout << "   start Objective " << endl;
}

void Xcsp3_to_Naxos::endObjectives()
{
        cout << "   end Objective " << endl;
}

void Xcsp3_to_Naxos::buildVariableInteger(string id, int minValue, int maxValue)
{
        cout << "    var " << id << " : " << minValue << "..." << maxValue
             << endl;
}

void Xcsp3_to_Naxos::buildVariableInteger(string id, vector<int>& values)
{
        cout << "    var " << id << " : ";
        cout << "        ";
        displayList(values);
}

void Xcsp3_to_Naxos::buildConstraintIntension(string id, string expr)
{
        cout << "\n    intension constraint : " << id << " : " << expr << endl;
}

void Xcsp3_to_Naxos::buildConstraintPrimitive(string id, OrderType op,
                                              XVariable* x, int k, XVariable* y)
{
        cout << "\n   intension constraint " << id << ": " << x->id
             << (k >= 0 ? "+" : "") << k << " op " << y->id << endl;
}

void Xcsp3_to_Naxos::buildConstraintExtension(string id,
                                              vector<XVariable*> list,
                                              vector<vector<int>>& tuples,
                                              bool support, bool hasStar)
{
        cout << "\n    extension constraint : " << id << endl;
        cout << "        " << (support ? "support" : "conflict")
             << " arity:" << list.size() << " nb tuples: " << tuples.size()
             << " star: " << hasStar << endl;
        cout << "        ";
        displayList(list);
}

void Xcsp3_to_Naxos::buildConstraintExtension(string id, XVariable* variable,
                                              vector<int>& tuples, bool support,
                                              bool hasStar)
{
        cout << "\n    extension constraint with one variable: " << id << endl;
        cout << "        " << (support ? "support" : "conflict")
             << " nb tuples: " << tuples.size() << " star: " << hasStar << endl;
        cout << (*variable) << endl;
}

void Xcsp3_to_Naxos::buildConstraintExtensionAs(string id,
                                                vector<XVariable*> list,
                                                bool support, bool hasStar)
{
        cout << "\n    extension constraint similar as previous one: " << id
             << endl;
}

void Xcsp3_to_Naxos::buildConstraintRegular(string id, vector<XVariable*>& list,
                                            string start, vector<string>& final,
                                            vector<XTransition>& transitions)
{
        cout << "\n    regular constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        start: " << start << endl;
        cout << "        final: ";
        displayList(final, ",");
        cout << endl;
        cout << "        transitions: ";
        for (unsigned int i = 0;
             i < (transitions.size() > 4 ? 4 : transitions.size()); i++) {
                cout << "(" << transitions[i].from << "," << transitions[i].val
                     << "," << transitions[i].to << ") ";
        }
        if (transitions.size() > 4)
                cout << "...";
        cout << endl;
}

void Xcsp3_to_Naxos::buildConstraintMDD(string id, vector<XVariable*>& list,
                                        vector<XTransition>& transitions)
{
        cout << "\n    mdd constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        transitions: ";
        for (unsigned int i = 0;
             i < (transitions.size() > 4 ? 4 : transitions.size()); i++) {
                cout << "(" << transitions[i].from << "," << transitions[i].val
                     << "," << transitions[i].to << ") ";
        }
        if (transitions.size() > 4)
                cout << "...";
        cout << endl;
}

void Xcsp3_to_Naxos::buildConstraintAlldifferent(string id,
                                                 vector<XVariable*>& list)
{
        cout << "\n    allDiff constraint" << id << endl;
        cout << "        ";
        displayList(list);
}

void Xcsp3_to_Naxos::buildConstraintAlldifferentExcept(string id,
                                                       vector<XVariable*>& list,
                                                       vector<int>& except)
{
        cout << "\n    allDiff constraint with exceptions" << id << endl;
        cout << "        ";
        displayList(list);
        cout << "        Exceptions:";
        displayList(except);
}

void Xcsp3_to_Naxos::buildConstraintAlldifferentList(
    string id, vector<vector<XVariable*>>& lists)
{
        cout << "\n    allDiff list constraint" << id << endl;
        for (unsigned int i = 0; i < (lists.size() < 4 ? lists.size() : 3);
             i++) {
                cout << "        ";
                displayList(lists[i]);
        }
}

void Xcsp3_to_Naxos::buildConstraintAlldifferentMatrix(
    string id, vector<vector<XVariable*>>& matrix)
{
        cout << "\n    allDiff matrix constraint" << id << endl;
        for (unsigned int i = 0; i < matrix.size(); i++) {
                cout << "        ";
                displayList(matrix[i]);
        }
}

void Xcsp3_to_Naxos::buildConstraintAllEqual(string id,
                                             vector<XVariable*>& list)
{
        cout << "\n    allEqual constraint" << id << endl;
        cout << "        ";
        displayList(list);
}

void Xcsp3_to_Naxos::buildConstraintNotAllEqual(string id,
                                                vector<XVariable*>& list)
{
        cout << "\n    not allEqual constraint" << id << endl;
        cout << "        ";
        displayList(list);
}

void Xcsp3_to_Naxos::buildConstraintOrdered(string id, vector<XVariable*>& list,
                                            OrderType order)
{
        cout << "\n    ordered constraint" << endl;
        string sep;
        if (order == LT)
                sep = " < ";
        if (order == LE)
                sep = " <= ";
        if (order == GT)
                sep = " > ";
        if (order == GE)
                sep = " >= ";
        cout << "        ";
        displayList(list, sep);
}

void Xcsp3_to_Naxos::buildConstraintLex(string id,
                                        vector<vector<XVariable*>>& lists,
                                        OrderType order)
{
        cout << "\n    lex constraint   nb lists: " << lists.size() << endl;
        string sep;
        if (order == LT)
                sep = " < ";
        if (order == LE)
                sep = " <= ";
        if (order == GT)
                sep = " > ";
        if (order == GE)
                sep = " >= ";
        cout << "        operator: " << sep << endl;
        for (unsigned int i = 0; i < lists.size(); i++) {
                cout << "        list " << i << ": ";
                cout << "        ";
                displayList(lists[i], " ");
        }
}

void Xcsp3_to_Naxos::buildConstraintLexMatrix(
    string id, vector<vector<XVariable*>>& matrix, OrderType order)
{
        cout << "\n    lex matrix constraint   matrix  " << endl;
        string sep;
        if (order == LT)
                sep = " < ";
        if (order == LE)
                sep = " <= ";
        if (order == GT)
                sep = " > ";
        if (order == GE)
                sep = " >= ";

        for (unsigned int i = 0; i < (matrix.size() < 4 ? matrix.size() : 3);
             i++) {
                cout << "        ";
                displayList(matrix[i]);
        }
        cout << "        Order " << sep << endl;
}

void Xcsp3_to_Naxos::buildConstraintSum(string id, vector<XVariable*>& list,
                                        vector<int>& coeffs, XCondition& cond)
{
        cout << "\n        sum constraint:";
        if (list.size() > 8) {
                for (int i = 0; i < 3; i++)
                        cout << (coeffs.size() == 0 ? 1 : coeffs[i]) << "*"
                             << *(list[i]) << " ";
                cout << " ... ";
                for (unsigned int i = list.size() - 4; i < list.size(); i++)
                        cout << (coeffs.size() == 0 ? 1 : coeffs[i]) << "*"
                             << *(list[i]) << " ";
        } else {
                for (unsigned int i = 0; i < list.size(); i++)
                        cout << (coeffs.size() == 0 ? 1 : coeffs[i]) << "*"
                             << *(list[i]) << " ";
        }
        cout << cond << endl;
}

void Xcsp3_to_Naxos::buildConstraintSum(string id, vector<XVariable*>& list,
                                        XCondition& cond)
{
        cout << "\n        unweighted sum constraint:";
        cout << "        ";
        displayList(list, "+");
        cout << cond << endl;
}

void Xcsp3_to_Naxos::buildConstraintSum(string id, vector<XVariable*>& list,
                                        vector<XVariable*>& coeffs,
                                        XCondition& cond)
{
        cout << "\n        scalar sum constraint:";
        if (list.size() > 8) {
                for (int i = 0; i < 3; i++)
                        cout << coeffs[i]->id << "*" << *(list[i]) << " ";
                cout << " ... ";
                for (unsigned int i = list.size() - 4; i < list.size(); i++)
                        cout << coeffs[i]->id << "*" << *(list[i]) << " ";
        } else {
                for (unsigned int i = 0; i < list.size(); i++)
                        cout << coeffs[i]->id << "*" << *(list[i]) << " ";
        }
        cout << cond << endl;
}

void Xcsp3_to_Naxos::buildConstraintAtMost(string id, vector<XVariable*>& list,
                                           int value, int k)
{
        cout << "\n    AtMost constraint: val=" << value << " k=" << k << endl;
        cout << "        ";
        displayList(list);
}

void Xcsp3_to_Naxos::buildConstraintAtLeast(string id, vector<XVariable*>& list,
                                            int value, int k)
{
        cout << "\n    Atleast constraint: val=" << value << " k=" << k << endl;
        cout << "        ";
        displayList(list);
}

void Xcsp3_to_Naxos::buildConstraintExactlyK(string id,
                                             vector<XVariable*>& list,
                                             int value, int k)
{
        cout << "\n    Exactly constraint: val=" << value << " k=" << k << endl;
        cout << "        ";
        displayList(list);
}

void Xcsp3_to_Naxos::buildConstraintAmong(string id, vector<XVariable*>& list,
                                          vector<int>& values, int k)
{
        cout << "\n    Among constraint: k=" << k << endl;
        cout << "        ";
        displayList(list);
        cout << "        values:";
        displayList(values);
}

void Xcsp3_to_Naxos::buildConstraintExactlyVariable(string id,
                                                    vector<XVariable*>& list,
                                                    int value, XVariable* x)
{
        cout << "\n    Exactly Variable constraint: val=" << value
             << " variable=" << *x << endl;
        cout << "        ";
        displayList(list);
}

void Xcsp3_to_Naxos::buildConstraintCount(string id, vector<XVariable*>& list,
                                          vector<int>& values, XCondition& xc)
{
        cout << "\n    count constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        values: ";
        cout << "        ";
        displayList(values);
        cout << "        condition: " << xc << endl;
}

void Xcsp3_to_Naxos::buildConstraintCount(string id, vector<XVariable*>& list,
                                          vector<XVariable*>& values,
                                          XCondition& xc)
{
        cout << "\n    count constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        values: ";
        displayList(values);
        cout << "        condition: " << xc << endl;
}

void Xcsp3_to_Naxos::buildConstraintNValues(string id, vector<XVariable*>& list,
                                            vector<int>& except, XCondition& xc)
{
        cout << "\n    NValues with exceptions constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        exceptions: ";
        displayList(except);
        cout << "        condition:" << xc << endl;
}

void Xcsp3_to_Naxos::buildConstraintNValues(string id, vector<XVariable*>& list,
                                            XCondition& xc)
{
        cout << "\n    NValues  constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        condition:" << xc << endl;
}

void Xcsp3_to_Naxos::buildConstraintCardinality(string id,
                                                vector<XVariable*>& list,
                                                vector<int> values,
                                                vector<int>& occurs,
                                                bool closed)
{
        cout << "\n    Cardinality constraint (int values, int occurs)  "
                "constraint closed: "
             << closed << endl;
        cout << "        ";
        displayList(list);
        cout << "        values:";
        displayList(values);
        cout << "        occurs:";
        displayList(occurs);
}

void Xcsp3_to_Naxos::buildConstraintCardinality(string id,
                                                vector<XVariable*>& list,
                                                vector<int> values,
                                                vector<XVariable*>& occurs,
                                                bool closed)
{
        cout << "\n    Cardinality constraint (int values, var occurs)  "
                "constraint closed: "
             << closed << endl;
        cout << "        ";
        displayList(list);
        cout << "        values:";
        displayList(values);
        cout << "        occurs:";
        displayList(occurs);
}

void Xcsp3_to_Naxos::buildConstraintCardinality(string id,
                                                vector<XVariable*>& list,
                                                vector<int> values,
                                                vector<XInterval>& occurs,
                                                bool closed)
{
        cout << "\n    Cardinality constraint (int values, interval occurs)  "
                "constraint closed: "
             << closed << endl;
        cout << "        ";
        displayList(list);
        cout << "        values:";
        displayList(values);
        cout << "        occurs:";
        displayList(occurs);
}

void Xcsp3_to_Naxos::buildConstraintCardinality(string id,
                                                vector<XVariable*>& list,
                                                vector<XVariable*> values,
                                                vector<int>& occurs,
                                                bool closed)
{
        cout << "\n    Cardinality constraint (var values, int occurs)  "
                "constraint closed: "
             << closed << endl;
        cout << "        ";
        displayList(list);
        cout << "        values:";
        displayList(values);
        cout << "        occurs:";
        displayList(occurs);
}

void Xcsp3_to_Naxos::buildConstraintCardinality(string id,
                                                vector<XVariable*>& list,
                                                vector<XVariable*> values,
                                                vector<XVariable*>& occurs,
                                                bool closed)
{
        cout << "\n    Cardinality constraint (var values, var occurs)  "
                "constraint closed: "
             << closed << endl;
        cout << "        ";
        displayList(list);
        cout << "        values:";
        displayList(values);
        cout << "        occurs:";
        displayList(occurs);
}

void Xcsp3_to_Naxos::buildConstraintCardinality(string id,
                                                vector<XVariable*>& list,
                                                vector<XVariable*> values,
                                                vector<XInterval>& occurs,
                                                bool closed)
{
        cout << "\n    Cardinality constraint (var values, interval occurs)  "
                "constraint closed: "
             << closed << endl;
        cout << "        ";
        displayList(list);
        cout << "        values:";
        displayList(values);
        cout << "        occurs:";
        displayList(occurs);
}

void Xcsp3_to_Naxos::buildConstraintMinimum(string id, vector<XVariable*>& list,
                                            XCondition& xc)
{
        cout << "\n    minimum  constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        condition: " << xc << endl;
}

void Xcsp3_to_Naxos::buildConstraintMinimum(string id, vector<XVariable*>& list,
                                            XVariable* index, int startIndex,
                                            RankType rank, XCondition& xc)
{
        cout << "\n    arg_minimum  constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        index:" << *index << endl;
        cout << "        Start index : " << startIndex << endl;
        cout << "        condition: " << xc << endl;
}

void Xcsp3_to_Naxos::buildConstraintMaximum(string id, vector<XVariable*>& list,
                                            XCondition& xc)
{
        cout << "\n    maximum  constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        condition: " << xc << endl;
}

void Xcsp3_to_Naxos::buildConstraintMaximum(string id, vector<XVariable*>& list,
                                            XVariable* index, int startIndex,
                                            RankType rank, XCondition& xc)
{
        cout << "\n    arg_maximum  constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        index:" << *index << endl;
        cout << "        Start index : " << startIndex << endl;
        cout << "        condition: " << xc << endl;
}

void Xcsp3_to_Naxos::buildConstraintElement(string id, vector<XVariable*>& list,
                                            int value)
{
        cout << "\n    element constant constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        value: " << value << endl;
}

void Xcsp3_to_Naxos::buildConstraintElement(string id, vector<XVariable*>& list,
                                            XVariable* value)
{
        cout << "\n    element variable constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        value: " << *value << endl;
}

void Xcsp3_to_Naxos::buildConstraintElement(string id, vector<XVariable*>& list,
                                            int startIndex, XVariable* index,
                                            RankType rank, int value)
{
        cout << "\n    element constant (with index) constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        value: " << value << endl;
        cout << "        Start index : " << startIndex << endl;
        cout << "        index : " << *index << endl;
}

void Xcsp3_to_Naxos::buildConstraintElement(string id, vector<XVariable*>& list,
                                            int startIndex, XVariable* index,
                                            RankType rank, XVariable* value)
{
        cout << "\n    element variable (with index) constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        value: " << *value << endl;
        cout << "        Start index : " << startIndex << endl;
        cout << "        index : " << *index << endl;
}

void Xcsp3_to_Naxos::buildConstraintChannel(string id, vector<XVariable*>& list,
                                            int startIndex)
{
        cout << "\n    channel constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        Start index : " << startIndex << endl;
}

void Xcsp3_to_Naxos::buildConstraintChannel(string id,
                                            vector<XVariable*>& list1,
                                            int startIndex1,
                                            vector<XVariable*>& list2,
                                            int startIndex2)
{
        cout << "\n    channel constraint" << endl;
        cout << "        list1 ";
        displayList(list1);
        cout << "        list2 ";
        displayList(list2);
}

void Xcsp3_to_Naxos::buildConstraintChannel(string id, vector<XVariable*>& list,
                                            int startIndex, XVariable* value)
{
        cout << "\n    channel constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        value: " << *value << endl;
}

void Xcsp3_to_Naxos::buildConstraintStretch(string id, vector<XVariable*>& list,
                                            vector<int>& values,
                                            vector<XInterval>& widths)
{
        cout << "\n    stretch constraint" << endl;
        cout << "        ";
        displayList(list);
        cout << "        values :";
        displayList(values);
        cout << "        widths:";
        displayList(widths);
}

void Xcsp3_to_Naxos::buildConstraintStretch(string id, vector<XVariable*>& list,
                                            vector<int>& values,
                                            vector<XInterval>& widths,
                                            vector<vector<int>>& patterns)
{
        cout << "\n    stretch constraint (with patterns)" << endl;
        cout << "        ";
        displayList(list);
        cout << "        values :";
        displayList(values);
        cout << "        widths:";
        displayList(widths);
        cout << "        patterns";
        for (unsigned int i = 0; i < patterns.size(); i++)
                cout << "(" << patterns[i][0] << "," << patterns[i][1] << ") ";
        cout << endl;
}

void Xcsp3_to_Naxos::buildConstraintNoOverlap(string id,
                                              vector<XVariable*>& origins,
                                              vector<int>& lengths,
                                              bool zeroIgnored)
{
        cout << "\n    nooverlap constraint" << endl;
        cout << "        origins";
        displayList(origins);
        cout << "        lengths";
        displayList(lengths);
}

void Xcsp3_to_Naxos::buildConstraintNoOverlap(string id,
                                              vector<XVariable*>& origins,
                                              vector<XVariable*>& lengths,
                                              bool zeroIgnored)
{
        cout << "\n    nooverlap constraint" << endl;
        cout << "        origins:";
        displayList(origins);
        cout << "        lengths";
        displayList(lengths);
}

void Xcsp3_to_Naxos::buildConstraintNoOverlap(
    string id, vector<vector<XVariable*>>& origins,
    vector<vector<int>>& lengths, bool zeroIgnored)
{
        cout << "\n    kdim (int lengths) nooverlap constraint" << endl;
        cout << "origins: " << endl;
        for (unsigned int i = 0; i < origins.size(); i++) {
                cout << "        ";
                displayList(origins[i]);
        }
        cout << "lengths: " << endl;
        for (unsigned int i = 0; i < origins.size(); i++) {
                cout << "        ";
                displayList(lengths[i]);
        }
}

void Xcsp3_to_Naxos::buildConstraintNoOverlap(
    string id, vector<vector<XVariable*>>& origins,
    vector<vector<XVariable*>>& lengths, bool zeroIgnored)
{
        cout << "\n    kdim (lenghts vars nooverlap constraint" << endl;
        cout << "origins: " << endl;
        for (unsigned int i = 0; i < origins.size(); i++) {
                cout << "        ";
                displayList(origins[i]);
        }
        cout << "lengths: " << endl;
        for (unsigned int i = 0; i < origins.size(); i++) {
                cout << "        ";
                displayList(lengths[i]);
        }
}

void Xcsp3_to_Naxos::buildConstraintInstantiation(string id,
                                                  vector<XVariable*>& list,
                                                  vector<int>& values)
{
        cout << "\n    instantiation constraint" << endl;
        cout << "        list:";
        displayList(list);
        cout << "        values:";
        displayList(values);
}

void Xcsp3_to_Naxos::buildObjectiveMinimizeExpression(string expr)
{
        cout << "\n    objective: minimize" << expr << endl;
}

void Xcsp3_to_Naxos::buildObjectiveMaximizeExpression(string expr)
{
        cout << "\n    objective: maximize" << expr << endl;
}

void Xcsp3_to_Naxos::buildObjectiveMinimizeVariable(XVariable* x)
{
        cout << "\n    objective: minimize variable " << x << endl;
}

void Xcsp3_to_Naxos::buildObjectiveMaximizeVariable(XVariable* x)
{
        cout << "\n    objective: maximize variable " << x << endl;
}

void Xcsp3_to_Naxos::buildObjectiveMinimize(ExpressionObjective type,
                                            vector<XVariable*>& list,
                                            vector<int>& coefs)
{
        XCSP3CoreCallbacks::buildObjectiveMinimize(type, list, coefs);
}

void Xcsp3_to_Naxos::buildObjectiveMaximize(ExpressionObjective type,
                                            vector<XVariable*>& list,
                                            vector<int>& coefs)
{
        XCSP3CoreCallbacks::buildObjectiveMaximize(type, list, coefs);
}

void Xcsp3_to_Naxos::buildObjectiveMinimize(ExpressionObjective type,
                                            vector<XVariable*>& list)
{
        XCSP3CoreCallbacks::buildObjectiveMinimize(type, list);
}

void Xcsp3_to_Naxos::buildObjectiveMaximize(ExpressionObjective type,
                                            vector<XVariable*>& list)
{
        XCSP3CoreCallbacks::buildObjectiveMaximize(type, list);
}
