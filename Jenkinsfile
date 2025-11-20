pipeline {
    agent any

    stages {
        
        stage('Checkout') {
            steps {
                echo 'Checking out repository...'
                checkout scm
            }
        }

        stage('Build') {
            steps {
                echo 'Building solution with MSBuild...'
                bat "\"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe\" \"C:\\Users\\Kub.Olaff\\Downloads\\vs_mkr_test1\\vs_mkr_test1\\test_repos.sln\" /p:Configuration=Debug /p:Platform=x64"
            }
        }

        stage('Run Tests') {
            steps {
                echo 'Running Google Tests...'
                bat "C:\\Users\\Kub.Olaff\\Downloads\\vs_mkr_test1\\vs_mkr_test1\\x64\\Debug\\test_repos.exe --gtest_output=xml:test_results.xml"
            }
        }

        stage('Test Report') {
            steps {
                echo 'Publishing test results...'
                junit 'C:\\Users\\Kub.Olaff\\Downloads\\vs_mkr_test1\\vs_mkr_test1\\x64\\Debug\\test_results.xml'
            }
        }
    }

    post {
        always {
            echo 'Pipeline finished.'
        }
    }
}
