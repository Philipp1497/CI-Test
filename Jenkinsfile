pipeline {
    agent any

    stage ('Checkout') {
        checkout([$class: 'GitSCM', branches: [[name: '*/master']],
            userRemoteConfigs: [[url: 'https://github.com/Philipp1497/CI-Test.git']]])
    }
    stage ('Checkout') {
        checkout([$class: 'GitSCM', branches: [[name: '*/master']],
    userRemoteConfigs: [[url: 'http://git-server/user/repository.git']]])
        git 'https://github.com/Philipp1497/CI-Test.git'
    }
    stages {
        stage('Build') {
            steps {
                // Get some code from a GitHub repository
               
                
                cd 'BS_Versuch1\Debug'
                make
                // Run Maven on a Unix agent.
                //sh "mvn -Dmaven.test.failure.ignore=true clean package"

                // To run Maven on a Windows agent, use
                // bat "mvn -Dmaven.test.failure.ignore=true clean package"
            }

            post {
                // If Maven was able to run the tests, even if some of the test
                // failed, record the test results and archive the jar file.
                success {
                    junit '**/target/surefire-reports/TEST-*.xml'
                    archiveArtifacts 'target/*.jar'
                }
            }
        }
    }
}
