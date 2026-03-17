#ifndef RUNTIMEPOLI_H
#define RUNTIMEPOLI_H

class RunTimePoliBase
{
public:
    virtual void print() const;
};

class RunTimePoliDerived : public RunTimePoliBase
{
public:
    void print() const override;
};

#endif
