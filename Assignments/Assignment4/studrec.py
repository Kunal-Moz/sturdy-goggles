import numpy as np

class StudentRecord :
    def __init__(self, line ) :
        self.firstname_ = ''
        self.lastname_ = ''
        self.score_ = 0.0
        self.scores_ = 0.0
        self.inputline(line)
        
    def __str__(self):
        return self.lastname_ + ', ' + self.firstname_ + ' : ' + ' '.join([str(x) for x in self.scores_])

    def firstname(self):
        return self.firstname_

    def lastname(self):
        return self.lastname_

    def score(self):
        return self.score_

    def inputline(self,data):
        self.lastname_ = data[0]
        self.firstname_ = data[1]
        self.scores_ = np.array([ float(x) for x in data[2:] ])

    def calcscore(self):
        ### your code goes here
        self.calcscore = np.dot(self.score_,self.scores_)
        return self.calcscore

class StudentRecordPhysics(StudentRecord):
    def __init__(self, line):
        ### your code goes here
        self.score_ = np.array([0.8,0.2])
    
        

class StudentRecordLiterature(StudentRecord):
    def __init__(self, line):
        ### your code goes here
        self.score_ = np.array([0.4,0.4,0.2])
        
        
    #def average_literature(self):
    #    self.average_literature = 0.4*self.scores_[0] + 0.4*self.scores_[1] + 0.2*self.scores_[2]
    #    return self.average_literature

class StudentRecordHistory(StudentRecord):
    def __init__(self, line):
        ### your code goes here
        self.score_ = np.array([])
        
    def average_history(self):
        if self.score > self.score_:
            self.average_history = 0.6*self.scores_[0] + 0.4*self.scores_[1]
        else:
            self.average_history = 0.4*self.scores_[1] + 0.6*self.scores_[0]


