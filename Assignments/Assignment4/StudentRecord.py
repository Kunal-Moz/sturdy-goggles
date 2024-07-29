import numpy as np

class StudentRecord :
    def __init__(self, line ) :
        self.firstname_ = ''
        self.lastname_ = ''
        self.score_ = None
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
    pass
    def __init__(self, line):
        ### your code goes here
        self.inputline(line)
        
    
    def weights(self):
        self.score_ = [0.8,0.2]
        return self.weights
    
    def average_phys(self):
        self.average_phys = 0.8*self.scores_[0] + 0.2*self.scores_[1]
        return self.average_phys


class StudentRecordLiterature(StudentRecord):
    pass
    def __init__(self, line):
        ### your code goes here
        self.inputline(line)
    
    def weights(self):
        self.score_ = [0.4,0.4,0.2]
        return self.score_

class StudentRecordHistory(StudentRecord):
    pass
    def __init__(self, line):
        ### your code goes here
        self.inputline(line)
    
    def weights(self):
        if self.scores_[0] > self.scores_[1]:
            self.score_ = [0.6,0.4]
        else:
            self.score_ = [0.4,0.6]
